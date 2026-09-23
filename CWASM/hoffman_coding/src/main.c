#include <stddef.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
	
#include "../include/frequency.h"
#include "../include/tree.h"
#include "../include/compress.h"

void decompress_test(char *output, char *reverse_enginerd,int *output_length, CharCode *table, int table_count, int lookup[256]);

int main(int argc, char *argv[]) {
	// char *input;
	// if (argc > 1) {
	// 	input = argv[1];
	// } else {
	// 	perror("You need pass in a exteranl argument for this to work");
	// }

	char input[] = "AABBBBBBBBBBBBBBbbbbbCCCCCCCddddeeF5yX+,crq+9hQrpRv)nt=nE7X.ma{KLtwt,+14nnQQyu;/,A--bfeS,BR$kZw30A.RfdT[yh4?yU)KwMDAX}zm;)&p+(bLGY+:zD?f-yUZweA4VPpp-r/1V3@-TY%h{*w0JVxNa;m+2ibK8_p$N++=S[v$&;R7Q.1WvnbE.m5N3MmXg1.2&=%,yv6AaJie/Bw9Fmq6z0VX]DmQZxwmx(YA-[8&!iN4/!xuGWP-rZ!i?0W,SBPh0X+Md+z03L%u)XyKpyQi6%wN*.P+eJw@5_AGVtN?mwv!zfJGE&hq9q;3%XvMbeDm2X9h.&*9pf[j2P?Pe#.g?a6-q6}@+AXR&5H@tP;pREvdbMDY;F)}y6jm@y+X/eAnEr_7z6aZf?0.?!dhxuE{SfBXzXTVbk8Fn{@eHEyA{&qDc1T$g(nK!Q1B3ie*6BATt2:F]Gf/B7b,yA]5;Jnc8adR$jhu4&Tb(z+RwXzDf46Yz=!i9BV2b1(LVUhVSnELdeB9c1T0jwcpqt%fq{PF)jD,++m({dL?wX=b{9!_vP%64m._+5RmG8:#JHdme]%vE@+N}g;qA{af.XizN&tiPL2w01$&9NugH(Rr*iC!a@{W5&tmv#JA76M]%5jn7!#X:Q;&n}P#H[4X5!iQ.hP/4N=hM,1/2P{!!iW+v-Rdv(r#E*9[gA,7i8?_{LuUX@[ce?S]#0kyu8dd1-YWc?P1hqm(AQ&Fi6HNr11,#Se8xCbitB?Ye]+-W3]9pDi*tTmmGk=NQMr?V}Ztz#vdfH)kV;he]4yrC%Yc)Q#FZk,B3gZmbnQ571&Z/BW(Gh6:u[[74D%hy(;C;1iMZ9[aFb9g_[LVU+.#+)T=f+%SD%_V0D;,vhqB2mqd((mu48P#$$.)JC_XC?jN.zkDpjB_7&@um((1Y3Uy]g%}P_w8YuMubi(Lr6d&)27VxHezx_q!]e.ZbPD@kR.m3W/d+ay:g+v;nmAJ+mtEL9JHj[Fgt[*HD4Z2LA%1!-L:dp."; 
	//5yX+,crq+9hQrpRv)nt=nE7X.ma{KLtwt,+14nnQQyu;/,A--bfeS,BR$kZw30A.RfdT[yh4?yU)KwMDAX}zm;)&p+(bLGY+:zD?f-yUZweA4VPpp-r/1V3@-TY%h{*w0JVxNa;m+2ibK8_p$N++=S[v$&;R7Q.1WvnbE.m5N3MmXg1.2&=%,yv6AaJie/Bw9Fmq6z0VX]DmQZxwmx(YA-[8&!iN4/!xuGWP-rZ!i?0W,SBPh0X+Md+z03L%u)XyKpyQi6%wN*.P+eJw@5_AGVtN?mwv!zfJGE&hq9q;3%XvMbeDm2X9h.&*9pf[j2P?Pe#.g?a6-q6}@+AXR&5H@tP;pREvdbMDY;F)}y6jm@y+X/eAnEr_7z6aZf?0.?!dhxuE{SfBXzXTVbk8Fn{@eHEyA{&qDc1T$g(nK!Q1B3ie*6BATt2:F]Gf/B7b,yA]5;Jnc8adR$jhu4&Tb(z+RwXzDf46Yz=!i9BV2b1(LVUhVSnELdeB9c1T0jwcpqt%fq{PF)jD,++m({dL?wX=b{9!_vP%64m._+5RmG8:#JHdme]%vE@+N}g;qA{af.XizN&tiPL2w01$&9NugH(Rr*iC!a@{W5&tmv#JA76M]%5jn7!#X:Q;&n}P#H[4X5!iQ.hP/4N=hM,1/2P{!!iW+v-Rdv(r#E*9[gA,7i8?_{LuUX@[ce?S]#0kyu8dd1-YWc?P1hqm(AQ&Fi6HNr11,#Se8xCbitB?Ye]+-W3]9pDi*tTmmGk=NQMr?V}Ztz#vdfH)kV;he]4yrC%Yc)Q#FZk,B3gZmbnQ571&Z/BW(Gh6:u[[74D%hy(;C;1iMZ9[aFb9g_[LVU+.#+)T=f+%SD%_V0D;,vhqB2mqd((mu48P#$$.)JC_XC?jN.zkDpjB_7&@um((1Y3Uy]g%}P_w8YuMubi(Lr6d&)27VxHezx_q!]e.ZbPD@kR.m3W/d+ay:g+v;nmAJ+mtEL9JHj[Fgt[*HD4Z2LA%1!-L:dp.
	//char input[] = "bccfffcddabddefeeeffe"; 
	char output[sizeof(input)]; 
	char new_str[sizeof(input)]; 

	Character *characters = NULL;
	int chararcters_count = 0;

	int result_freq_count = frequency_count(input, &characters,&chararcters_count);	
	if (result_freq_count != SUCCESS) {
		printf("Something went wrong, error code: %d", result_freq_count);
	}

	CharCode *table = NULL;
	int table_count = 0;

	int lookup[256];
	for (int i = 0; i < 256; i++) {
		lookup[i] = -1;
	}

	int result_huff_tree_make = make_huffman_tree(&characters,&chararcters_count, &table, &table_count, lookup);	
	if (result_huff_tree_make != SUCCESS) {
		printf("Something went wrong, error code: %d", result_huff_tree_make);
	}

	int output_length;
	compress(input, output, &output_length ,table, table_count, lookup);

	//printf("Output length: %d bytes\n", output_length);
	// for (int i = 0; i < output_length; i++) {
	//    		printf("%02X ", (unsigned char)output[i]);
	// }
	// printf("\n"); // prints the raw hex

	decompress_test(output, new_str, &output_length, table, table_count,lookup);
	printf("Input: %s\n", input);
	printf("New Str: %s\n", new_str);

	free(characters);
	free(table);
	return 0;
}

void decompress_test(char *output, char *reverse_enginerd,int *output_length, CharCode *table, int table_count, int lookup[256]) {
	int padding = (unsigned char) output[0];
	int total_bits = (*output_length - 1) * 8 - padding;
	char current_code[256] = "";
	int code_len = 0;
	int out_pos = 0;

	for (int bit_num = 0; bit_num < total_bits; bit_num++) {
		int byte_index = 1 + (bit_num / 8);
		int bit_in_byte = bit_num % 8;

		int bit = (output[byte_index] >> (7 - bit_in_byte)) & 1;

		current_code[code_len] = bit ? '1' : '0';
		code_len++;
		current_code[code_len] = '\0';

		for (int i = 0; i < table_count; i++) {
			if (strcmp(current_code, table[i].code) == 0) {
				reverse_enginerd[out_pos] = table[i].charName;	
				out_pos++;

				code_len = 0;
				current_code[0] = '\0';
				break;
			}
		}
	}

	reverse_enginerd[out_pos] = '\0';
}
