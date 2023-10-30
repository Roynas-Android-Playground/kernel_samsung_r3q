#/bin/bash
set -e

[ ! -e "toolchain" ] && echo "Make toolchain avaliable at $(pwd)/toolchain" && exit

export KBUILD_BUILD_USER=Royna
export KBUILD_BUILD_HOST=GrassLand

git submodule update --init

PATH=$PWD/toolchain/bin:$PATH
COMMON_FLAGS="O=out ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- LLVM=1 -j$(nproc)"
rm -rf out

make $COMMON_FLAGS r3q_defconfig
make $COMMON_FLAGS savedefconfig
cp out/defconfig arch/arm64/configs/r3q_defconfig
make O=out $COMMON_FLAGS
