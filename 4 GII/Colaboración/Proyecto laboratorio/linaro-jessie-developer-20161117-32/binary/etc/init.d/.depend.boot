TARGETS = mountkernfs.sh hostname.sh udev keyboard-setup mountdevsubfs.sh console-setup mountall.sh mountall-bootclean.sh mountnfs.sh mountnfs-bootclean.sh hwclock.sh networking alsa-utils checkroot.sh urandom resolvconf lm-sensors pppd-dns plymouth-log kmod x11-common kbd checkroot-bootclean.sh bootmisc.sh checkfs.sh procps
INTERACTIVE = udev keyboard-setup console-setup checkroot.sh kbd checkfs.sh
udev: mountkernfs.sh
keyboard-setup: mountkernfs.sh udev
mountdevsubfs.sh: mountkernfs.sh udev
console-setup: mountall.sh mountall-bootclean.sh mountnfs.sh mountnfs-bootclean.sh kbd
mountall.sh: checkfs.sh checkroot-bootclean.sh
mountall-bootclean.sh: mountall.sh
mountnfs.sh: mountall.sh mountall-bootclean.sh networking
mountnfs-bootclean.sh: mountall.sh mountall-bootclean.sh mountnfs.sh
hwclock.sh: mountdevsubfs.sh
networking: mountkernfs.sh mountall.sh mountall-bootclean.sh urandom resolvconf procps
alsa-utils: mountall.sh mountall-bootclean.sh mountnfs.sh mountnfs-bootclean.sh
checkroot.sh: hwclock.sh mountdevsubfs.sh hostname.sh keyboard-setup
urandom: mountall.sh mountall-bootclean.sh hwclock.sh
resolvconf: mountall.sh mountall-bootclean.sh
lm-sensors: mountall.sh mountall-bootclean.sh mountnfs.sh mountnfs-bootclean.sh
pppd-dns: mountall.sh mountall-bootclean.sh
plymouth-log: mountall.sh mountall-bootclean.sh mountnfs.sh mountnfs-bootclean.sh
kmod: checkroot.sh
x11-common: mountall.sh mountall-bootclean.sh mountnfs.sh mountnfs-bootclean.sh
kbd: mountall.sh mountall-bootclean.sh mountnfs.sh mountnfs-bootclean.sh
checkroot-bootclean.sh: checkroot.sh
bootmisc.sh: checkroot-bootclean.sh mountall.sh mountall-bootclean.sh mountnfs.sh mountnfs-bootclean.sh udev
checkfs.sh: checkroot.sh
procps: mountkernfs.sh mountall.sh mountall-bootclean.sh udev
