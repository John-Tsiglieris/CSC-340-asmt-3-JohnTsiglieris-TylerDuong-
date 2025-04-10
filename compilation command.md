g++ -c Amazon340.cpp -o out/Amazon340.o
g++ -c AmazonMain.cpp -o out/AmazonMain.o
g++ -c Good.cpp -o out/Good.o
g++ -c Media.cpp -o out/Media.o
g++ -c Product.cpp -o out/Product.o
g++ -c Vendor.cpp -o out/Vendor.o
g++ out/Amazon340.o out/AmazonMain.o out/Good.o out/Media.o out/Product.o out/Vendor.o -o prog
./out/prog

gcc -c Amazon340.cpp -o out/Amazon340.o
gcc -c AmazonMain.cpp -o out/AmazonMain.o
gcc -c Good.cpp -o out/Good.o
gcc -c Media.cpp -o out/Media.o
gcc -c Product.cpp -o out/Product.o
gcc -c Vendor.cpp -o out/Vendor.o
gcc out/Amazon340.o out/AmazonMain.o out/Good.o out/Media.o out/Product.o out/Vendor.o -o prog
./out/prog
