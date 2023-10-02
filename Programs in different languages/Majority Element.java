class MajorityElement
{
    static int majorityElement(int a[], int size)
    {
        // your code here
       HashMap<Integer,Integer> map=new HashMap<>();
        for (int i = 0; i < size; i++) {
            int value = map.getOrDefault(a[i], 0);
            map.put(a[i], value + 1);
        }
        for (Map.Entry<Integer, Integer> it : map.entrySet()) {
            if (it.getValue() > (size / 2)) {
                return it.getKey();
            }
        }

        return -1;
    }
}