class Solution {
public:
    int maxProduct(vector<string>& words) {
        std::sort(words.begin(),words.end(),myfunction);
        vector<int> bitmap(words.size(),0);
        for(int i=0;i<words.size();i++){
            cout<<words[i]<<endl;
            for(int j=0;j<words[i].size();j++){
                bitmap[i]|=(1<<(words[i][j]-'a'));
            }
        }
        int maxres=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                int noShare=(bitmap[i])&(bitmap[j]) ;
                if(!noShare){
                    int product=words[i].length()*words[j].length();
                    if(product>maxres){
                        maxres=product;
                    }
                }
            }
        }
        return maxres;
    }
    static bool myfunction (string i,string j) { return (i.length()>j.length()); } //decending
};