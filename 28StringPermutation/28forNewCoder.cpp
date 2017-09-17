//输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
//输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.size()==0)
            return m_result;
        Permutation(str,0);
        sort(m_result.begin(),m_result.end());
        return m_result;
    }
    void Permutation(string str,int begin){
        if(begin==str.size()-1){
            m_result.push_back(str);
            return;
        }
        for(int i=begin;i<str.size();i++){
            if(i!=begin&&str[begin]==str[i])
                    continue;
            swap(str[begin],str[i]);//将第一个数依次与后续数交换
            Permutation(str,begin+1);//余下的递归全排列
            swap(str[begin],str[i]);//还原序列，以便下一次交换
        }
    }
private:
    vector<string> m_result;
};
