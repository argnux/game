# Build

```
git clone https://github.com/argnux/game.git
cd game
cmake -DCMAKE_INSTALL_PREFIX=$your-install-path -DCMAKE_BUILD_TYPE=Release -G Ninja -S . -B ./build
cmake --build ./build --target install --config Release -j 6
```
_Note: you need to install SDL3 and SDL3_image before building and specify CMAKE_PREFIX_PATH if needed._

# Run

### Windows
- Extract .zip to some directory.
- Run game from this directory.

### Linux
- Make directory (e.g., game) and follow this.
- Unzip .zip using `unzip`
- Extract tarball using `tar -xvf $tarball_path`
- Run game.
