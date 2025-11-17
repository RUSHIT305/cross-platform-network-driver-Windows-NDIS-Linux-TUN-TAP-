/*
 * Simple Linux kernel net_device skeleton (educational example).
 * THIS FILE IS ONLY A SKELETON and is NOT READY FOR PRODUCTION.
 *
 * To build a kernel module from this you need kernel headers and a proper
 * Makefile that builds against the running kernel. This example is here
 * for reference only.
 */
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>

static struct net_device *skeleton_dev;

static int skeleton_open(struct net_device *dev) {
    netif_start_queue(dev);
    pr_info("skeleton: open\n");
    return 0;
}

static int skeleton_stop(struct net_device *dev) {
    netif_stop_queue(dev);
    pr_info("skeleton: stop\n");
    return 0;
}

static netdev_tx_t skeleton_start_xmit(struct sk_buff *skb, struct net_device *dev) {
    pr_info("skeleton: start_xmit len=%u\n", skb->len);
    // In a real driver, transmit the packet to hardware here
    dev_kfree_skb(skb);
    return NETDEV_TX_OK;
}

static const struct net_device_ops skeleton_netdev_ops = {
    .ndo_open = skeleton_open,
    .ndo_stop = skeleton_stop,
    .ndo_start_xmit = skeleton_start_xmit,
};

static int __init skeleton_init(void) {
    int result;
    skeleton_dev = alloc_etherdev(0);
    if (!skeleton_dev) return -ENOMEM;
    skeleton_dev->netdev_ops = &skeleton_netdev_ops;
    strcpy(skeleton_dev->name, "sks%d");
    result = register_netdev(skeleton_dev);
    if (result) {
        free_netdev(skeleton_dev);
        return result;
    }
    pr_info("skeleton: registered\n");
    return 0;
}

static void __exit skeleton_exit(void) {
    unregister_netdev(skeleton_dev);
    free_netdev(skeleton_dev);
    pr_info("skeleton: unloaded\n");
}

module_init(skeleton_init);
module_exit(skeleton_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("cross-netdriver");
MODULE_DESCRIPTION("Net device skeleton - educational example");
