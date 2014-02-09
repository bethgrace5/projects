package reddit;


import java.util.ArrayList;
import java.util.Scanner;
public class easy126 {

	/**
	 * Accepts an unSorted array and a Sorted array. Merges them, 
	 * and arranges the product in numerical order.
	 * @param unSorted int array
	 * @param sorted int array
	 * @return merged int ArrayList
	 */
	public static ArrayList<Integer> mergeSort( int [] unSorted, int [] sorted){
	
		ArrayList<Integer> merged = new ArrayList<Integer>();
		boolean notDone = true;
		/* first element is 0 so that if the unsorted element to add is less than
		 * the smallest sorted element, it is guaranteed to be added to the beginning of merged.
		*/
		merged.add(0);
		//initialize merged with sorted list to add unsorted elements in their correct place.
		for(int element:sorted){
			merged.add(element);
		}
		for(int j=0 ; j<unSorted.length; j++){
			notDone=true;
		for(int i = merged.size()-1 ; i>=0 && notDone;i--){
			if(unSorted[j]>merged.get(i)){
				merged.add(i+1, unSorted[j]);
				notDone = false;
			}
		}
		//zeros are removed for clarity. (prompt removes zeros).
	}for (int i=0; i<merged.size(); i++){
		if (merged.get(i)==0){
			merged.remove(i);
			i--;
		}
	}
		return merged;
	}
	public static void main(String[]args){
		Scanner in = new Scanner(System.in);
		
		//get unsorted list
		System.out.println("Enter number of unsorted items.");
		int numUnsorted=in.nextInt();
		int [] unSorted = new int [numUnsorted];
		System.out.println("Enter unsorted list: ");
		for (int i=0; i<numUnsorted; i++){
			unSorted[i]=in.nextInt();
		}
		//get sorted list
		System.out.println("Enter number of Sorted Items.");
		int numSorted = in.nextInt();
		int [] sorted = new int [numSorted];
		System.out.println("Enter sorted list: ");
		for (int i=0; i<numSorted; i++){
			sorted[i]=in.nextInt();
		}
		in.close();
		//implement method and print to check.
		ArrayList<Integer> result = new ArrayList<Integer>();
		result = mergeSort(unSorted, sorted);
		System.out.println(result);
		
	}	
}

