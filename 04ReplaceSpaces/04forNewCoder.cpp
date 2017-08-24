//请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str==NULL || length ==0)
            return;
        int nNum=0;
        int i=0;
        int nLen=0;
        while(str[i]!='\0'){
            ++nLen;//字符串实际总长度
            if(str[i]==' '){
                ++nNum;
            }
            ++i;
        }
        int nTail=nLen+nNum*2;
        if(nTail>length)
            return;
        while(nLen>=0&&nTail>nLen){
            if(str[nLen]==' '){
                str[nTail--]='0';
                str[nTail--]='2';
                str[nTail--]='%';
            }
            else{
                str[nTail--]=str[nLen];
            }
            --nLen;
        }

	}
};
