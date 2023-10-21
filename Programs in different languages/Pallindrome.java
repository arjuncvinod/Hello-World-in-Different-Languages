class Pallindrome {
    public boolean isPalindrome(int x) {
        int x1=x; int n=0; int rev=0; 
        while(x>0)
        {
           n=x%10;
           rev=(rev*10)+n;
           x=x/10;
        }
        if(x1==rev)
        {
            return true;
        }
        else 
        {
            return false;
        }
      
    }
}