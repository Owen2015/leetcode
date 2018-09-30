char* reverseString(char* s){
	//char* forward=s;
	char* b=s;
	char temp;
	printf("b is %c, \n",*b);

	while(*b){
		b++;
		printf(" processing %c \n",*b);
	}
	b--;
	while(b>s){
	temp=*s;
	*s=*b;
	*b=temp;
	b--;
	s++;
	printf("address  s: %d,char: %c, b:%d, char: %c \n",s,*s,b,*b);
	}
	return s;
}
	
int firstUniqChar(char* s){
	char* p1;
	char* p2;
	p1=s;
	int flag;
	while(*p1){
		p2=s;
		//p2++;
		flag=1;
		while(*p2){
			if(p1==p2){
				p2++;
				continue;
			}
			else if(*p1==*p2){
				flag=0;
				break;
			}
			p2++;
		}
		if(flag==1){
			return p1-s;
		}
		p1++;
	}
	return -1;
}

int firstUniqChar_best(char* s){
	int tab[26]={0};
	int curr_c;
	int i=0;
	while(curr_c=s[i++]!='\0'){
		tab[curr_c-'a']++;
	}
	i=0;
	while((curr_c=s[i])!='\0'){
		if(tab[curr_c-'a']==1){
			return i;
		}
		i++;
	}
	return -1;
}	
			
int isAnagram(char* s, char* t){
	int tab1[26]={0};
	int tab2[26]={0};
	int i=0;
	int curr_c;
	while((curr_c=s[i++])!='\0'){
		tab1[curr_c-'a']++;
	}
	i=0;
	while((curr_c=t[i++])!='\0'){
		tab2[curr_c-'a']++;
	}
	i=0;
	while(i<26){
//	printf(" %d : s:%d , t:%d \n",i,tab1[i],tab2[i]);
		if(tab1[i]!=tab2[i]){
			return 0;
		}
		i++;
	}
	return 1;
}		

int isPalindrome(char* s){
	char* start=s;
	char* end=s;
	int i=0;
	while(*s!='\0')s++;
	end=s;
	while(end>start){
		printf("every case end :%c, start:%c \n ",*end,*start);
		if(isUpperCaseAlpha(*start)) *start=toLowerCase(*start);
		if(isUpperCaseAlpha(*end)) *end=toLowerCase(*end);
		if(*end==*start){
			end--;
			start++;
		}else{
			if(isAlphaNumeric(*end)&&isAlphaNumeric(*start)){
				printf("equal case end :%c, start:%c \n",*end,*start);
				return 0;
			}

			if(!isAlphaNumeric(*end)){
				end--;
			}
			if(!isAlphaNumeric(*start)){
				start++;
			}		
		}
	}
	return 1;
}


int toLowerCase(int c){
	return c-'A'+'a';
}
int isNumeric(int c){
	if(c>='0'&&c<='9') return 1;
	else return 0;
}
int isLowerCaseAlpha(int c){
	if(c>='a'&&c<='z') return 1;
	else return 0;
}
int isUpperCaseAlpha(int c){
	if(c>='A'&&c<='Z') return 1;
	else return 0;
}
int isAlpha(int c){
	if(isLowerCaseAlpha(c)||isUpperCaseAlpha(c)) return 1;
	else return 0;
}
int isAlphaNumeric(int c){
	if(isNumeric(c)||isAlpha(c)) return 1;
	else return 0;
}
	
void printAscii(){
	int i;
	for(i=0;i<256;i++){
		printf("%d %c \n",i,i);
	}
}

int isPalindromeBest(char* s) {
    int i,length=0;
    int size=strlen(s);
    char *a=(char *)malloc(sizeof(char)*size);
    char *b=(char *)malloc(sizeof(char)*size);
    for(i=0;i<size;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            a[length++]=s[i];
        else if(s[i]>='a'&&s[i]<='z')
            a[length++]=s[i];
        else if(s[i]>='A'&&s[i]<='Z')
            a[length++]=s[i]-'A'+'a';
    }
    for(i=length-1;i>=0;i--)
    {
        b[length-1-i]=a[i];
    }
    for(i=0;i<length;i++)
        if(a[i]!=b[i])
            return 0;
    return 1;
}

int strStr(char* haystack, char* needle){
	if(*haystack=='\0'||*needle=='\0')return 0;
	char* p1;
	char* p2;
	char* index;
	index=haystack;
	p1=haystack;
	p2=needle;
	int state=0;
	while(*index!='\0'){
		while(*p2!='\0'){
			if(*p2==*p1){
				state=1;
				p1++;
				p2++;
			}else{
				state=0;
				break;
			}
		}
		if(state==1){
			return index-haystack;
		}else{
			index++;
			p1=index;
			p2=needle;
		}
	}
	return -1;
		
}
int strStrBest(char* haystack, char* needle) {
    int i,j,cp;
    if(*needle=='\0')
        return 0;
    for(cp=0;haystack[cp]!='\0';cp++)
    {
        j=0;
        i=cp;
        while(needle[j]!='\0'&&haystack[i]!='\0')
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else break;
        }
        if(needle[j]=='\0')
            return cp;
        else if(haystack[i]=='\0')
            return -1;
    }
    return -1;
}
int isUniqChar(char* s){
        int i;
        int b[26];
        int len=strlen(s);
        for(i=0;i<26;i++){
                b[i]=0;
        }
        for(i=0;i<len;i++){
                b[s[i]-'a']+=1;
        }
        for(i=0;i<26;i++){
                if(b[i]>1){
                        return 0;
                }
        }
        return 1;
}

char* substr(char *string, int position, int length) {
   char *pointer;
   int c;

   pointer = malloc(length+1);

   if (pointer == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(1);
   }

   for (c = 0 ; c < length ; c++)
   {
      *(pointer+c) = *(string+position-1);
      string++;
   }

   *(pointer+c) = '\0';

   return pointer;
}

