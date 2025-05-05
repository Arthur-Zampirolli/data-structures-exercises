echo "building and running...\n"
rm -r build
mkdir -p build
cd build
cmake .. -GNinja && ninja
./main