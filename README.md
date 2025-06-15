# data-structures-exercises
Data structures exercises from class

## Para buildar as soluções em c++ da lista 2:
    Tenha o CMake 4.0 e o ninja. Basta rodar o script run.sh que se encontra na pasta src/cpp/lista2 
    O esquema de build foi testado no Ubuntu 24.
# Guia instalação
## Ubuntu 24.04
    snap install cmake
wget -O - https://apt.llvm.org/llvm.sh | sudo bash -s -- 20
sudo apt update

# Install Clang 20 and its tools
snap install cmake 
sudo apt install clang-20
sudo apt install clang-tools-20
sudo apt install libclang-20-dev

# Verify the installation
clang-20 --version