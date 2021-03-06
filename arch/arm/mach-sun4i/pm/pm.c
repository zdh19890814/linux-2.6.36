/*
*********************************************************************************************************
*                                                    LINUX-KERNEL
*                                        AllWinner Linux Platform Develop Kits
*                                                   Kernel Module
*
*                                    (c) Copyright 2006-2011, kevin.z China
*                                             All Rights Reserved
*
* File    : pm.c
* By      : kevin.z
* Version : v1.0
* Date    : 2011-5-27 14:08
* Descript: power manager for allwinners chips platform.
* Update  : date                auther      ver     notes
*********************************************************************************************************
*/

#include <linux/module.h>
#include <linux/suspend.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/slab.h>
#include <linux/major.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include <asm/delay.h>
#include <asm/io.h>
#include <linux/power/aw_pm.h>

#define AW_PM_DBG   1
#undef PM_DBG
#if(AW_PM_DBG)
    #define PM_DBG(format,args...)   printk("[pm]"format,##args)
#else
    #define PM_DBG(format,args...)   do{}while(0)
#endif

/* define major number for power manager */
#define AW_PMU_MAJOR    267


extern char *standby_bin_start;
extern char *standby_bin_end;

static struct aw_pm_info standby_info = {
    .standby_para = {
        .event = SUSPEND_WAKEUP_SRC_EXINT,
    },
    .pmu_arg = {
        .twi_port = 0,
        .dev_addr = 10,
    },
};
static struct cdev *pmu_cdev=NULL;
static struct device *pmu_device=NULL;
static dev_t  pmu_dev;
static struct class *pm_class;



/*
*********************************************************************************************************
*                           aw_pm_valid
*
*Description: determine if given system sleep state is supported by the platform;
*
*Arguments  : state     suspend state;
*
*Return     : if the state is valid, return 1, else return 0;
*
*Notes      : this is a call-back function, registered into PM core;
*
*********************************************************************************************************
*/
static int aw_pm_valid(suspend_state_t state)
{
    PM_DBG("valid\n");

    if(!((state > PM_SUSPEND_ON) && (state < PM_SUSPEND_MAX))){
        PM_DBG("state (%d) invalid!\n", state);
        return 0;
    }

    return 1;
}


/*
*********************************************************************************************************
*                           aw_pm_begin
*
*Description: Initialise a transition to given system sleep state;
*
*Arguments  : state     suspend state;
*
*Return     : return 0 for process successed;
*
*Notes      : this is a call-back function, registered into PM core, and this function
*             will be called before devices suspened;
*********************************************************************************************************
*/
int aw_pm_begin(suspend_state_t state)
{
    PM_DBG("%d state begin\n", state);

    return 0;
}


/*
*********************************************************************************************************
*                           aw_pm_prepare
*
*Description: Prepare the platform for entering the system sleep state.
*
*Arguments  : none;
*
*Return     : return 0 for process successed, and negative code for error;
*
*Notes      : this is a call-back function, registered into PM core, this function
*             will be called after devices suspended, and before device late suspend
*             call-back functions;
*********************************************************************************************************
*/
int aw_pm_prepare(void)
{
    PM_DBG("prepare\n");

    return 0;
}


/*
*********************************************************************************************************
*                           aw_pm_prepare_late
*
*Description: Finish preparing the platform for entering the system sleep state.
*
*Arguments  : none;
*
*Return     : return 0 for process successed, and negative code for error;
*
*Notes      : this is a call-back function, registered into PM core.
*             prepare_late is called before disabling nonboot CPUs and after
*              device drivers' late suspend callbacks have been executed;
*********************************************************************************************************
*/
int aw_pm_prepare_late(void)
{
    PM_DBG("prepare_late\n");

    return 0;
}


/*
*********************************************************************************************************
*                           aw_pm_enter
*
*Description: Enter the system sleep state;
*
*Arguments  : state     system sleep state;
*
*Return     : return 0 is process successed;
*
*Notes      : this function is the core function for platform sleep.
*********************************************************************************************************
*/
static int aw_pm_enter(suspend_state_t state)
{
    int (*standby)(struct aw_pm_info *arg) = (int (*)(struct aw_pm_info *arg))SRAM_FUNC_START;

    PM_DBG("enter state %d\n", state);

    //move standby code to sram
    memcpy((void *)SRAM_FUNC_START, (void *)&standby_bin_start, (int)&standby_bin_end - (int)&standby_bin_start);

    /* config system wakeup evetn type */
    standby_info.standby_para.event = SUSPEND_WAKEUP_SRC_EXINT | SUSPEND_WAKEUP_SRC_ALARM;
	/* goto sram and run */
	standby(&standby_info);

    return 0;
}


/*
*********************************************************************************************************
*                           aw_pm_wake
*
*Description: platform wakeup;
*
*Arguments  : none;
*
*Return     : none;
*
*Notes      : This function called when the system has just left a sleep state, right after
*             the nonboot CPUs have been enabled and before device drivers' early resume
*             callbacks are executed. This function is opposited to the aw_pm_prepare_late;
*********************************************************************************************************
*/
static void aw_pm_wake(void)
{
    PM_DBG("platform wakeup, wakesource is:0x%x\n", standby_info.standby_para.event);
}


/*
*********************************************************************************************************
*                           aw_pm_finish
*
*Description: Finish wake-up of the platform;
*
*Arguments  : none
*
*Return     : none
*
*Notes      : This function is called right prior to calling device drivers' regular suspend
*              callbacks. This function is opposited to the aw_pm_prepare function.
*********************************************************************************************************
*/
void aw_pm_finish(void)
{
    PM_DBG("platform wakeup finish\n");
}


/*
*********************************************************************************************************
*                           aw_pm_end
*
*Description: Notify the platform that system is in work mode now.
*
*Arguments  : none
*
*Return     : none
*
*Notes      : This function is called by the PM core right after resuming devices, to indicate to
*             the platform that the system has returned to the working state or
*             the transition to the sleep state has been aborted. This function is opposited to
*             aw_pm_begin function.
*********************************************************************************************************
*/
void aw_pm_end(void)
{
    PM_DBG("aw_pm_end!\n");
}


/*
*********************************************************************************************************
*                           aw_pm_recover
*
*Description: Recover platform from a suspend failure;
*
*Arguments  : none
*
*Return     : none
*
*Notes      : This function alled by the PM core if the suspending of devices fails.
*             This callback is optional and should only be implemented by platforms
*             which require special recovery actions in that situation.
*********************************************************************************************************
*/
void aw_pm_recover(void)
{
    PM_DBG("aw_pm_recover\n");
}


/*
    define platform_suspend_ops which is registered into PM core.
*/
static struct platform_suspend_ops aw_pm_ops = {
    .valid = aw_pm_valid,
    .begin = aw_pm_begin,
    .prepare = aw_pm_prepare,
    .prepare_late = aw_pm_prepare_late,
    .enter = aw_pm_enter,
    .wake = aw_pm_wake,
    .finish = aw_pm_finish,
    .end = aw_pm_end,
    .recover = aw_pm_recover,
};


/*
*********************************************************************************************************
*                           aw_set_pmu
*
*Description: set parameters for pmu device.
*
*Arguments  : arg   pm information from user;
*
*Return     : result,
*
*Notes      : pmu is a virtual char device for user access.
*
*********************************************************************************************************
*/
static int aw_set_pmu(struct aw_pm_info *arg)
{
    struct aw_pm_info   tmp_arg;

    copy_from_user((void *)&tmp_arg, (void *)arg, sizeof(struct aw_pm_info));

    /* check if parameter is valid */
    if((tmp_arg.pmu_arg.twi_port < 0) || (tmp_arg.pmu_arg.twi_port > 2))
    {
        printk("pmu paraeter invlalid(standby_para.twi_port:%d\n)!\n", arg->pmu_arg.twi_port);
        return -1;
    }

    memcpy((void *)&standby_info, (void *)arg, sizeof(struct aw_pm_info));

    return 0;
}


/*
*********************************************************************************************************
*                           aw_pmu_ioctl
*
*Description: function for user control pmu virtual device.
*
*Arguments  : pfile pmu device handle;
*             cmd   command for pmu device operation;
*             arg   arguments for pmu device operation;
*
*Return     : result;
*
*Notes      :
*
*********************************************************************************************************
*/
static long aw_pmu_ioctl(struct file *pfile, unsigned int cmd, unsigned long arg)
{
    int ret = -EINVAL;

    PM_DBG("aw_pmu_ioctl\n");

    switch(cmd){
    case AW_PMU_SET:
        ret = aw_set_pmu((struct aw_pm_info *)arg);
        break;
    default:
        break;
    }

    return ret;
}


static struct file_operations pmudev_fops= {
    .owner  = THIS_MODULE,
    .unlocked_ioctl = aw_pmu_ioctl,
};


/*
*********************************************************************************************************
*                           aw_pm_init
*
*Description: initial pm sub-system for platform;
*
*Arguments  : none;
*
*Return     : result;
*
*Notes      :
*
*********************************************************************************************************
*/
static int __init aw_pm_init(void)
{
    int     result;

    PM_DBG("aw_pm_init!\n");

    pmu_dev = MKDEV(AW_PMU_MAJOR,0);
    result = register_chrdev_region(pmu_dev,PMU_MAX_DEVS,"aw_pmu");
    if(result){
        printk(KERN_ERR "alloc_chrdev_region() failed for pmu\n");
        return -EIO;
    }

    pmu_cdev = kzalloc(sizeof(struct cdev),GFP_KERNEL);
    if(!pmu_cdev){
        printk(KERN_ERR "malloc memory  fails for pmu device\n");
        unregister_chrdev_region(pmu_dev,PMU_MAX_DEVS);
        return -ENOMEM;
    }

    cdev_init(pmu_cdev, &pmudev_fops);
    if(cdev_add(pmu_cdev, pmu_dev, 1))
        goto out_err;

    pm_class = class_create(THIS_MODULE, "pm_class");
    if (IS_ERR(pm_class)){
        printk(KERN_ERR"create class error\n");
        return -EPERM;
    }

    pmu_device = device_create(pm_class, NULL, pmu_dev, NULL, "pm");

    suspend_set_ops(&aw_pm_ops);

    return 0;

out_err:
    printk(KERN_ERR "register failed  for pmu device\n");
    kfree(pmu_cdev);
    unregister_chrdev_region(pmu_dev, PMU_MAX_DEVS);
    return -ENODEV;
}


/*
*********************************************************************************************************
*                           aw_pm_exit
*
*Description: exit pm sub-system on platform;
*
*Arguments  : none
*
*Return     : none
*
*Notes      :
*
*********************************************************************************************************
*/
static void __exit aw_pm_exit(void)
{
    PM_DBG("aw_pm_exit!\n");

    device_destroy(pm_class, pmu_dev);
    class_destroy(pm_class);

    if(pmu_cdev)
    {
        cdev_del(pmu_cdev);
        kfree(pmu_cdev);
    }
    unregister_chrdev_region(pmu_dev,PMU_MAX_DEVS);

    suspend_set_ops(NULL);
}

module_init(aw_pm_init);
module_exit(aw_pm_exit);

