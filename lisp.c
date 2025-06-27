/*The MIT License (MIT)

Copyright © 2025 Artem Podlegaev 


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <editline.h>
//#include <editline/history.h>

#define SCAN_BUFFER 1024

#define PROMT_STRING "user>>"

char* is_keyword(char in) {
	if (in == ' ') return "space";
	//if (strcmp(in, "\0") == 0) return " ";
	if (in == '(' || in == ')') return "sk";

	if (in == '+') return "plus";
	if (in == '-') return "minus";

	if (isdigit(in)) return "digit";

	return "\0";
	//if (in == "expt") return "expt";
}

void scan(char* input) {
	printf("%s\n", input);
	
	for (int i = 0; i < sizeof(input); ++i) {
		printf("%c\n", input[i]);
		printf("%s\n", is_keyword(input[i]));

		if (isalpha(input[i])) {
			int j = i;
			while (isalpha(input[j]) && input[j] != ' ') {
				printf("%c", input[j]);
				++j;
			}
			i = j;
		}
	}
	/*char dij = '';
	int df = 0, cf = 0;
	for (char* i = arr; *i != '\0'; ++i) {
		printf("%c\n", *i);
		if (isdigit(*i)) {
			printf("%s", "hello");
		}
	}*/

}

int main(int argc, char** argv) {
	puts("Lisp version 0.0.1\n");
	puts("Press Ctrl+d to exit\n");

	while (1) {
		char* input = readline(PROMT_STRING);
		scan(input);
		if (!input) {
			printf("\n");
			return 0;
		}
	}
} 
