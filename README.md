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

## Contribuer

1. Fork le depot

2. Cloner votre fork

```
git clone https://github.com/votre-pseudo/projet-commun.git
```

3. Creer une branche

```
git branch -C feat/votre-feature
```

Il existe plusieurs comme "feat/" (feature), "fix/", "ref/" (refactor).

4. Faire vos changements

5. Formatter vos changements

```
clang-format fichier-modifie
```

6. Commit vos changements

```
git add .
git commit -m "feat: votre feature"
```

7. Push vers votre fork

```
git push origin feat/votre-feature
```

8. Ouvrir une pull-request
