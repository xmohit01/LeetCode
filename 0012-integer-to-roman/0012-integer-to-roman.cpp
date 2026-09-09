class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int dig;
        if(num >= 1000){
            dig = num / 1000;
            if(dig == 1){
                ans += "M";
                num -= 1000;
            }
            if(dig == 2){
                ans += "MM";
                num -= 2000;
            }
            if(dig == 3){
                ans += "MMM";
                num -= 3000;
            }
        }

        if(num >= 900){
            ans += "CM";
            num -= 900;
        }

        if(num >= 500){
            ans += "D";
            num -= 500;
        }

        if(num >= 100){
            dig = num / 100;
            if(dig == 1){
                ans += "C";
                num -= 100;
            }
            else if(dig == 2){
                ans += "CC";
                num -= 200;
            }
            else if(dig == 3){
                ans += "CCC";
                num -= 300;
            }
            else if(dig == 4){
                ans += "CD";
                num -= 400;
            }
        }

        if(num >= 90){
            ans += "XC";
            num -= 90;
        }

        if(num >= 50){
            ans += "L";
            num -= 50;
        }

        if(num >= 10){
            dig = num / 10;
            if(dig == 1){
                ans += "X";
                num -= 10;
            }
            else if(dig == 2){
                ans += "XX";
                num -= 20;
            }
            else if(dig == 3){
                ans += "XXX";
                num -= 30;
            }
            else if(dig == 4){
                ans += "XL";
                num -= 40;
            }
        }

        if(num >= 9){
            ans += "IX";
            num -= 9;
        }

        if(num >= 5){
            ans += "V";
            num -= 5;
        }

        if(num >= 1){
            dig = num;
            if(dig == 1){
                ans += "I";
                num -= 1;
            }
            else if(dig == 2){
                ans += "II";
                num -= 2;
            }
            else if(dig == 3){
                ans += "III";
                num -= 3;
            }
            else if(dig == 4){
                ans += "IV";
                num -= 4;
            }
        }

        return ans;
    }
};