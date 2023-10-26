fn insertion_sort(arr: &mut [i32]) {
    let len = arr.len();
    
    for i in 1..len {
        let mut j = i;
        
        while j > 0 && arr[j] < arr[j - 1] {
            arr.swap(j, j - 1);
            j -= 1;
        }
    }
}

fn main() {
    let mut arr = [12, 11, 13, 5, 6];
    
    insertion_sort(&mut arr);

    println!("Sorted array: {:?}", arr);
}
