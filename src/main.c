#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint8_t testSeqNumber1[] = { 0x31 };
uint8_t testSeqNumber2[] = { 0x31, 0x19};
uint8_t testSeqNumber3[] = { 0x31, 0xD9, 0x0C };
uint8_t testSeqNumber4[] = { 0x31, 0xD9, 0x8C, 0x06 };
uint8_t testSeqNumber5[] = { 0x31, 0xD9, 0x8C, 0x56, 0x03 };
uint8_t testSeqNumber6[] = { 0x31, 0xD9, 0x8C, 0x56, 0xB3, 0x01 };
uint8_t testSeqNumber7[] = { 0x31, 0xD9, 0x8C, 0x56, 0xB3, 0xDD, 0x00 };
uint8_t testSeqNumber8[] = { 0x31, 0xD9, 0x8C, 0x56, 0xB3, 0xDD, 0x70, 0x31 };
uint8_t testSeqNumber9[] = { 0x31, 0xD9, 0x8C, 0x56, 0xB3, 0xDD, 0x70, 0x31 , 0x19 };
uint8_t testSeqHelloWorld[] = { 0xC8, 0x32, 0x9B, 0xFD, 0x6E, 0x28, 0xEE, 0x6F, 0x39, 0x9B, 0x0C };
uint8_t testSeqPrice[] = { 0x54, 0x74, 0x19, 0x04, 0x97, 0xA7, 0xC7, 0x65, 0x50, 0x7A, 0x0E, 0x8A, 0xC1, 0x04 };
uint8_t testSeqGTS[] = { 0x54, 0x74, 0x7A, 0x0E, 0x3A, 0x52, 0xA7, 0x20, 0x72, 0xD9, 0x9C, 0x76, 0x97, 0xE7, 0x20, 0x3A, 0xBA, 0x0C, 0x62, 0x87, 0xDD, 0xE7, 0x7A, 0xF8, 0x5C, 0x6E, 0xCD, 0xE1, 0xE5, 0x71, 0xDA, 0x9C, 0x1E, 0x83, 0xE4, 0xE5, 0x78, 0x3D, 0x2D, 0x2F, 0xB7, 0xCB, 0x6E, 0xFA, 0x1C, 0x64, 0x7E, 0xCB, 0x41, 0xC7, 0x69, 0x13, 0x74, 0x4F, 0xD3, 0xD1, 0x69, 0x37, 0x88, 0x8E, 0x2E, 0x83, 0xC8, 0xE9, 0x73, 0x9A, 0x1E, 0x66, 0x83, 0xC6, 0x65, 0x36, 0xBB, 0xCE, 0x0E, 0xCB, 0xE9, 0x65, 0x76, 0x79, 0xFC, 0x6E, 0xB7, 0xEB, 0xEE, 0xF4, 0x38, 0x4C, 0x4F, 0xBF, 0xDD, 0x73, 0xD0, 0x3C, 0x3F, 0xA7, 0x97, 0xDB, 0x20, 0x14, 0x14, 0x1D, 0x9E, 0x97, 0x41, 0xB2, 0x17, 0x14, 0x1D, 0x9E, 0x97, 0x41, 0xB2, 0x55, 0xCA, 0x05 };
uint8_t testSeqInfo[] = { 0xD3, 0xB2, 0x9B, 0x0C, 0x0A, 0xBB, 0x41, 0xE5, 0x76, 0x38, 0xCD, 0x06, 0xD1, 0xDF, 0xA0, 0xB4, 0xDB, 0xFC, 0x06, 0xA4, 0xDD, 0xF4, 0xB2, 0x9B, 0x9C, 0x0E, 0xBB, 0xC6, 0xEF, 0x36 };

char asciiTable[] = {'@' , ' ' , '$' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '\n', ' ' , ' ' , '\r', ' ' , ' ',

                    ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ',
                    ' ' , '!' , '"' , '#' , ' ' , '%' , '&' , '\'', '(' , ')' , '*' , '+' , ',' , '-' , '.' , '/',
                    '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , ':' , ';' , '<' , '=' , '>' , '?',
                    ' ' , 'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O',
                    'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z' , ' ' , ' ' , ' ' , ' ' , ' ',
                    ' ' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o',
                    'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z' , ' ' , ' ' , ' ' , ' ' , ' '};

#define ASCII_TABLE_SIZE 128

/* Show 8 bit ASCII message
 * If character is not valid, replace with space
 *
 * message: 8 bit ASCII array
 * length8bits: Length in bytes of the array
 *
 * returns: nothing
 */
void showAsciiMessage(char *message, uint32_t length8bits)
{
    uint8_t value;

    printf("Decoded = '");
    while(length8bits --)
    {
	value = (uint8_t)*message;
	if (value < ASCII_TABLE_SIZE) 
        {
            printf("%c", asciiTable[value]);
	}
	else
        {
            printf(" ");
        }
        message ++;
    }
    printf("'\r\n");
}

/* Decodes a 7 bit GSM encoding array to 8 bit ASCII array
 *
 * input: ASCII 7 bit GSM array
 * length7bits: Length in bytes of the input array
 * decoded: Output with the decoded 8 bit ASCII array
 * length8bits: Length in bytes of the output array
 *
 * returns: nothing
 */
void decode(uint8_t *input, uint32_t length7bits, char *decoded, uint32_t *length8bits)
{
    uint8_t restb = 0;
    uint8_t mask = 0;
    char *ref = decoded;

    while(length7bits --)
    {
        mask = 0x7f >> restb;
        *decoded += (*input & mask) << restb;
        *(++ decoded) = (*input & (~ mask)) >> (7 - restb);
        restb = (restb + 1) % 7;
	if (!restb) {
	    decoded ++;
        }
        input ++;
    }
    if (*(decoded - 1) == 0)
    {
        decoded --;
    }
    *length8bits = (uint8_t)(decoded - ref);
}


/* Encodes an 8 bit ASCII array to 7 bit GSM encoding.
 *
 * input: ASCII array
 * length8bits: Length in bytes of the input array
 * encodedLen: Output with the encoded length
 * length7bits: Length in bytes of the output array
 *
 * returns: nothing
 */
void encode(char *input, uint32_t length8bits, uint8_t *encoded, uint32_t *length7bits)
{
    uint8_t restb = 0;
    uint8_t *ref = encoded;

    while(length8bits --)
    {
	if (restb) 
        {
            *encoded += (*input & (0x7f >> (7 - restb))) << (8 - restb);
	    encoded ++;
        }
        *encoded = *input >> restb;
	restb = (restb + 1) % 8;
        input++;
    }
    if (restb)
    {
        encoded ++;
    }
    *length7bits = (uint8_t)(encoded - ref);
}

/* Tests an encoded array, it first decodes the message and prints the ASCII output and then
* reencodes it back to compare with the original encoded version, if the encoded array does
 * not match the original one it will print an error message.
 *
 * encodedText: array with the 7 bit encoded text
 *
 * returns: nothing
 */
void testCoDec(uint8_t *encodedText, uint32_t originalLen)
{
    uint8_t decoded[256] = {0};
    uint8_t encoded[256] = {0};
    uint32_t decodedLen = 0;
    uint32_t encodedLen = 0;

    decode(encodedText, originalLen, (char *)decoded, &decodedLen);
    showAsciiMessage((char *)decoded, decodedLen);
    encode((char*)decoded, decodedLen, encoded, &encodedLen);

    if (originalLen == encodedLen)
    {
        if (memcmp(encodedText, encoded, originalLen))
	{
            printf("Error encode result does not match original encoded text\r\n");
	}
    }
    else
    {
        printf("Error encoded-decoded length mismatch (%d/%d)\r\n", originalLen, encodedLen);
    }
}

/* Test program for the 7BIT CodDec
 *
 * argc: Argument count
 * argv: Argument list
 *
 * returns: program exit status
 */
int main(int argc, char **argv)
{
    testCoDec(testSeqNumber1, sizeof(testSeqNumber1));
    testCoDec(testSeqNumber2, sizeof(testSeqNumber2));
    testCoDec(testSeqNumber3, sizeof(testSeqNumber3));
    testCoDec(testSeqNumber4, sizeof(testSeqNumber4));
    testCoDec(testSeqNumber5, sizeof(testSeqNumber5));
    testCoDec(testSeqNumber6, sizeof(testSeqNumber6));
    testCoDec(testSeqNumber7, sizeof(testSeqNumber7));
    testCoDec(testSeqNumber8, sizeof(testSeqNumber8));
    testCoDec(testSeqNumber9, sizeof(testSeqNumber9));
    testCoDec(testSeqHelloWorld, sizeof(testSeqHelloWorld));
    testCoDec(testSeqPrice, sizeof(testSeqPrice));
    testCoDec(testSeqGTS, sizeof(testSeqGTS));
    testCoDec(testSeqInfo, sizeof(testSeqInfo));
}
