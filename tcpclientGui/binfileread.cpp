//#include "binfileread.h"

//BinFileRead::BinFileRead()
//{

//}
//#include <stdio.h>
//#include <string.h>
//FILE *f;
//char buffer[4096];
//int r,a;
//void HexDump(char *buf,int len,int addr) {
//    int i,j,k;
//    char binstr[80];

//    for (i=0;i<len;i++) {
//        if (0==(i%16)) {
//            sprintf(binstr,"%08x -",i+addr);
//            sprintf(binstr,"%s %02x",binstr,(unsigned char)buf[i]);
//        } else if (15==(i%16)) {
//            sprintf(binstr,"%s %02x",binstr,(unsigned char)buf[i]);
//            sprintf(binstr,"%s  ",binstr);
//            for (j=i-15;j<=i;j++) {
//                sprintf(binstr,"%s%c",binstr,('!'<buf[j]&&buf[j]<='~')?buf[j]:'.');
//            }
//            printf("%s\n",binstr);
//        } else {
//            sprintf(binstr,"%s %02x",binstr,(unsigned char)buf[i]);
//        }
//    }
//    if (0!=(i%16)) {
//        k=16-(i%16);
//        for (j=0;j<k;j++) {
//            sprintf(binstr,"%s   ",binstr);
//        }
//        sprintf(binstr,"%s  ",binstr);
//        k=16-k;
//        for (j=i-k;j<i;j++) {
//            sprintf(binstr,"%s%c",binstr,('!'<buf[j]&&buf[j]<='~')?buf[j]:'.');
//        }
//        printf("%s\n",binstr);
//    }
//}
//int main(int argc,char **argv) {
//    if (argc<2) {
//        fprintf(stderr,"Usage: %s filename.ext\n",argv[0]);
//        return 2;
//    }
//    f=fopen(argv[1],"rb");
//    if (NULL==f) {
//        fprintf(stderr,"Can not open file [%s]!\n",argv[1]);
//        return 1;
//    }
//    a=0;
//    while (1) {
//        r=fread(buffer,1,4096,f);
//        HexDump(buffer,r,a);
//        a+=r;
//        if (r<4096) break;
//    }
//    fclose(f);
//    return 0;
//}
