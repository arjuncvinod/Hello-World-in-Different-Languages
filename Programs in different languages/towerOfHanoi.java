class towerOfHanoi {

    public static void hanoi(int n,String source , String helper , String destination){ //1,2,3
        if(n==1){
            System.out.println("transfer"+ n +" disc "+" from "+source +" to "+destination);
            return;
        }
        hanoi(n-1, source, destination, helper); // 1,3,2
        System.out.println(" transfer "+ n +" disc "+" from "+source +" to "+destination);
        hanoi(n-1, helper, source, destination); //2,1,3
    }
    public static void main(String[] args) {
        int n = 2;
        hanoi(n, "S", "H", "D");
    }
}
