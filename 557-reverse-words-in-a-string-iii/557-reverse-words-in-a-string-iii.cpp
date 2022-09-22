class Solution {
public:
    string reverseWords(string s){
        
        string str="",str2="";
       int i=0,j=0;
       for(int k=0;k<s.length();k++){
           
          if(s[k]==' '){
              j=k;
               reverse(s.begin()+i, s.begin()+j);
              i=j+1;
              
               
          } 
          // reverse(s.begin()+i,s.length()-1);
          
           
           
       }
        reverse(s.begin()+i,s.end());
        return s;
        
    }
};