using System;

namespace MyStringNamespace{
    class MyString{
        private string str;
        public MyString(string s){
            str = s;
        }
        public bool Check(){
            foreach (char c in str){

                if (!char.IsDigit(c)){
                    return false;
                }
            }
            return true;
        }
        public int Length(){
            return str.Length;
        }
        public void RemoveFive(){

            int pos = str.IndexOf('5');
            while (pos != -1){
                str = str.Remove(pos, 1);
                pos = str.IndexOf('5');
            }
        }
        public int Length2(){
            return str.Length;
        }
        public void Print(){
            Console.WriteLine(str);
        }
    }
}
