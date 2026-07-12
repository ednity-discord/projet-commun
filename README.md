# projet-commun

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

On oublie pas d'utiliser `clang-format` pour formatter le code avant de
commit.
