public class Solution {
    public string IntToRoman(int num) {
        
        Dictionary<int, string>num2rome = new Dictionary<int, string>();
        num2rome.Add(0,"");
        num2rome.Add(1,"I");
        num2rome.Add(10,"X");
        num2rome.Add(100,"C");
        num2rome.Add(1000,"M");
        num2rome.Add(5,"V");
        num2rome.Add(50,"L");
        num2rome.Add(500,"D");
        num2rome.Add(4, "IV");
        num2rome.Add(40, "XL");
        num2rome.Add(400, "CD");
        num2rome.Add(9, "IX");
        num2rome.Add(90, "XC");
        num2rome.Add(900, "CM");
        
        
        string[] n0 = new string[] {"", "0", "00", "000"};
        string nstr = Convert.ToString(num);
        ArrayList arraylist = new ArrayList();
        for(int i = 0; i < nstr.Length; i++){
            arraylist.Add(Convert.ToInt32(nstr[i]+n0[nstr.Length - i - 1]));
        }
        
        string n2r(int i)
            {
                string ret = "";
                string slove = string.Empty;
                if(num2rome.TryGetValue(i, out slove))
                {
                    ret += slove;
                    return ret;
                 }
                //else
                if(i > 1000)
                {
                    ret = "M" + n2r(i-1000);
                    return ret;
                }
                    
                if(i > 500)
                {
                    ret = "D" + n2r(i-500);
                    return ret;
                }
                if(i > 100)
                {
                    ret = "C" + n2r(i-100);
                    return ret;
                }
                if(i > 50)
                {
                    ret = "L" + n2r(i-50);
                    return ret;
                }
                if(i > 10)
                {
                    ret = "X" + n2r(i-10);
                    return ret;
                }
                if(i > 5)
                {
                    ret = "V" + n2r(i-5);
                    return ret;
                }
                if(i > 1)
                {
                    ret = "I" + n2r(i-1);
                    return ret;
                }
                return "wrong!";
            }
        
        string res = "";
        foreach(int i in arraylist){
            res += n2r(i);
        }
        
        return res;
    }
}