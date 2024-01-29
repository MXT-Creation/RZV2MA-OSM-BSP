# Meta-rz-features
This is a Yocto build layer that provides features of Renesas.

### Meta-renesas-ai
This layer provides AI tools support to the Renesas RZ/G2 and RZ/G2L families of SoCs.\
URI: https://github.com/renesas-rz/meta-renesas-ai

`Meta-renesas-ai` is a submodule of `meta-rz-features`, so you need to download it by following below instruction:\
Setup git configuration:
``` bash
git config --global user.email "you@example.com"
git config --glocal user.name "Your Name"
```

Assume that `$WORK` is your current working directory:
``` bash
cd $WORK/meta-rz-features
# Download submodule
git submodule update --init
# Update lastest source of submodule
git submodule update --recursive --remote
git pull --recurse-submodules
```
