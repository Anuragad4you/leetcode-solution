class Solution {
public:
    string reverseWords(string s){
        
        
       int i=0,j=0;
        string str1="",ans="";
       for(int k=0;k<s.length();k++){
           if(s[k]!=' '){
                str1+=s[k];
           }
          
          if(s[k]==' '){
              
              reverse(str1.begin(), str1.end());
              
              
            ans+=str1+" ";  
                str1="";
          } 
          // reverse(s.begin()+i,s.length()-1);
          
           
           
       }
        reverse(str1.begin(), str1.end());
            ans=ans+str1; 
        
        return ans;
        
    }
};