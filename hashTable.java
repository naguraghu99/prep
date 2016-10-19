import java.util.ArrayList;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map;
import java.util.Scanner;

public class hashTable {

	public static HashMap<String,Integer> getStringFrequency(String[] text){
		HashMap<String,Integer> magazineFreq = new HashMap<String,Integer>();
		for(String word: text){
			if(!magazineFreq.containsKey(word)){
				magazineFreq.put(word, 0);
			}
			magazineFreq.put(word, magazineFreq.get(word)+1);
		}
		return magazineFreq;
	}
	public static boolean canBuildRansomNote(HashMap<String,Integer> magazineFreq,HashMap<String,Integer> noteFreq){
		for(Map.Entry<String, Integer> entry: noteFreq.entrySet()){
			String word = entry.getKey();
			if(!(magazineFreq.containsKey(word)) || magazineFreq.get(word) < entry.getValue()){
				return false;
			}
		}
		return true;
	}
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        int n = in.nextInt();
        if ( (1 > m && m > 30000) || (1 > n && n > 30000)){
        	return;
        }
        
        ArrayList<String> outPut = new ArrayList<String>();
        String magazine[] = new String[m];
        for(int magazine_i=0; magazine_i < m; magazine_i++){
            magazine[magazine_i] = in.next();
            if (magazine[magazine_i].length() > 5 || magazine[magazine_i].length() < 1){
            	return;
            }
        }
        String ransom[] = new String[n];
        for(int ransom_i=0; ransom_i < n; ransom_i++){
            ransom[ransom_i] = in.next();
            if (ransom[ransom_i].length() > 5 || ransom[ransom_i].length() < 1){
            	return;
            }
        }
        HashMap<String,Integer> magazine_frequency = getStringFrequency(magazine);
        HashMap<String,Integer> ransom_frequency = getStringFrequency(ransom);
        if(canBuildRansomNote(magazine_frequency,ransom_frequency)){
        	System.out.println("Yes");
        }else {
        	System.out.println("No");
        }
        
        in.close();
    }
}