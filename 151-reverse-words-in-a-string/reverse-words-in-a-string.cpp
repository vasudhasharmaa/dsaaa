class Solution {
public:
    string reverseWords(string s) {
        string word="";
        vector<string>words;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                word+=s[i];

            }
            else
            {
                if(word!="")
                {
                    words.push_back(word);
                    word="";
                }
            }
            
        }
        if(word!="")
            {
                words.push_back(word);

            }
            if(words.size() == 0) return "";
            int left=0;
            int right=words.size()-1;
            while(left<right)
            {
                swap(words[left],words[right]);
                left++;
                right--;
            }
            
        string snew;
        for(int i=0;i<words.size()-1;i++)
        {
            snew.append(words[i]);
            snew.append(" ");
            
        }
        if(!words.empty()) snew.append(words[words.size()-1]);
        return snew;

        
    }
};