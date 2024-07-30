#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf

void dump(void* p, size_t n) {
	uint8_t* u8 = static_cast<uint8_t*>(p);
	size_t i = 0;
	while (true) {
		printf("%02X ", *u8++);
		if (++i >= n) break;
		if (i % 8 == 0)
			printf("\n");
	}
	printf("\n");
}

void write_4660() {
	uint16_t port = 4660; // 0x1234
	printf("port number = %d\n", port);
	dump(&port, sizeof(port));
}

uint16_t my_htons(uint16_t n) {
	uint16_t temp = 0xff00;
	uint16_t temp1 = 0x00ff;
	temp = n & temp; // 0x3400
	temp = temp >> 8;
	temp1 = n & temp1; // 0x0012
	temp1 = temp1 << 8;
	return temp | temp1;
}

void  write_0x1234() {
	uint8_t network_buffer[] = { 0x12, 0x34 };
	uint16_t* p = reinterpret_cast<uint16_t*>(network_buffer);
	uint16_t n = my_htons(*p); // TODO
	printf("16 bit number=0x%x\n", n);
}

uint32_t my_ntohl(uint32_t n) {
	int n1 = (n & 0xff000000) >> 24;
	int n2 = (n & 0x00ff0000) >> 8;
	int n3 = 0x0000ff00;
	int n4 = 0x000000ff;
	n3 = n & n3;
	n4 = n & n4;
	n3 <<= 8;
	n4 <<= 24;
	return n1 | n2 | n3 | n4;
}


void  write_0x12345678() {
	uint8_t network_buffer[] = { 0x12, 0x34, 0x56, 0x78 };
	uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
	uint32_t n = my_ntohl(*p); // TODO
	printf("32 bit number=0x%x\n", n);
}

int main() {
//	write_4660();
//	write_0x1234();
	write_0x12345678();
}
