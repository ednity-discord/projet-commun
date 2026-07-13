# projet-commun

## Dependances

Pour pouvoir travailler correctement sur ce projet il vous faudra:
- meson
- ninja
- clang-format

<details><summary>Sous Window (MSYS2 MinGW)</summary>

Il vous faudra en plus installer [MSYS2](https://www.msys2.org/) pour
travailler dessus.

```
pacman -S mingw-w64-x86_64-meson mingw-w64-x86_64-ninja mingw-w64-x86_64-toolchain mingw-w64-x86_64-clang
```

</details>

<details><summary>Sous Arch</summary>

```
sudo pacman -S meson ninja clang
```

</details>

<details><summary>Sous Ubuntu/Debian</summary>

```
sudo apt install meson ninja-build clang-format
```

</details>

## Compilation

```
meson setup build
ninja -C build
```

Ou en debuggage:

```
meson setup build --buildtype=release
ninja -C build
```
