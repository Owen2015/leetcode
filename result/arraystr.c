int isAnagram(char* s, char* t) {
    int* sCount=(int*)calloc(26,sizeof(int));
    int* tCount=(int*)calloc(26,sizeof(int));
    
    char* now=s;
    while(*now!='\0'){
        sCount[*now-'a']++;
        now++;
    }
    
    now=t;
    while(*now!='\0'){
        tCount[*now-'a']++;
        now++;
    }
    
    for(int i=0;i<26;i++){
        if(sCount[i]!=tCount[i])return 0;
    }
    return 1;
}

/*
 *  * 函数名称： 有效的字母异位词
 *   * 函数功能：给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
 *    * 理解：两个单词的字母仅排列方式不同。
 *     * 示例：
 *      		示例 1:
 *
 *      				输入: s = "anagram", t = "nagaram"
 *      						输出: true
 *      								示例 2:
 *
 *      										输入: s = "rat", t = "car"
 *      												输出: false
 *      												 */
bool isAnagram2(char *s, char *t) {
	int hashs[26];
	int hasht[26];
	int i;
	int hashSize = 26;
	for ( i = 0; i < hashSize; i++) {
		hashs[i] = 0;
		hasht[i] = 0;
	}
	i = 0;
	while ( s[i] != '\0' && t[i] != '\0') {
		(hashs[ s[i] - 'a'])++;
		(hasht[ t[i] - 'a'])++;
		i++;
	}
	if ( s[i] != t[i])
		return false;
	for ( i = 0; i < hashSize; i++) {
		if ( hashs[i] != hasht[i])
			return false;
	}
	return true;
}

int firstUniqChar(char* s) {
    int* posArr=(int*)calloc(26,sizeof(int));
    int pos=1;
    while(*s!='\0'){
        if(posArr[*s-'a']<0){
            
        }
        else if(posArr[*s-'a']==0){
            posArr[*s-'a']=pos;
        }
        else{
            posArr[*s-'a']=-1;
        }
        pos++;
        s++;
    }
    
    int ret=INT_MAX;
    for(int i=0;i<26;i++){
        if(posArr[i]>0&&posArr[i]<ret){
            ret=posArr[i];
        }
    }
    if(ret==INT_MAX)
        ret=0;
    return ret-1;
}

int firstUniqChar(char* s) {
    int i,j;
    int len=strlen(s);
    int b[26];
    for(int k=0;k<26;k++)
    {
        b[k]=0;
    }
    for(i=0;i<len;i++)
    {
        b[s[i]-'a']+=1;
    }
    for(j=0;j<len;j++)
    {
        if(b[s[j]-'a']==1)
        {
            return j;
        }
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
