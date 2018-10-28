# Rockchip RK3399 UEFI Firmware

## Notes

This is a version of the Rockchip 3399 UEFI firmware from https://github.com/jeffchenfz/Rockchip
updated to build with the latest [edk2](https://github.com/tianocore/edk2)/[edk2-platforms](https://github.com/tianocore/edk2-platforms)
(as of 2018.10.28).

## Building on vanilla Debian GNU/Linux 9.1

```
apt-get install build-essential acpica-tools nasm uuid-dev gcc-aarch64-linux-gnu
# If you want to use a different workspace, change the target directory below
export WORKSPACE=~/workspace
mkdir $WORKSPACE
cd $WORKSPACE
git clone https://github.com/tianocore/edk2.git
git clone https://github.com/tianocore/edk2-non-osi.git
git clone https://github.com/tianocore/edk2-platforms.git
git clone https://github.com/pbatard/Rockchip.git edk2-platforms/Platform/Rockchip
export GCC5_AARCH64_PREFIX=aarch64-linux-gnu-
export PACKAGES_PATH=$WORKSPACE/edk2:$WORKSPACE/edk2-platforms:$WORKSPACE/edk2-non-osi
. edk2/edksetup.sh
make -C edk2/BaseTools
build -a AARCH64 -t GCC5 -p edk2-platforms/Platform/Rockchip/Rk3399Pkg/Rk3399-SDK.dsc -b DEBUG
edk2-platforms/Platform/Rockchip/Rk3399Pkg/Tools/loaderimage --pack --uboot Build/Rk3399-SDK/DEBUG_GCC5/FV/RK3399_SDK_UEFI.fd RK3399_SDK_UEFI.img
```

## Flashing the UEFI firmware

After the .img has been created, use [Rockchip AndroidTool](https://github.com/rockchip-linux/tools/tree/rk3399/windows)
to flash the firmware by using `RK3399_SDK_UEFI.img` for the `uboot.img`.

You can find the rest of the files required for flashing (`loader.bin`, `parameter.txt` and `trust.img`)
under `Rk3399Pkg/Tools/Bin/`
