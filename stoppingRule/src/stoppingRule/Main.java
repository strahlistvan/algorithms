package stoppingRule;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
	
	public static void main(String[] args) {
		final int TOILET_COUNT = 100;
		final double REJECT_LIMIT = 0.37;
		final int REJECT_COUNT = (int) (REJECT_LIMIT*TOILET_COUNT);
		final int TEST_COUNT = 1000;
		
		System.out.println("REJECT_COUNT "+REJECT_COUNT);

		int successCount = 0;
		for (int i=0; i<TEST_COUNT; ++i) {
			List<Integer> toiletList = getRandomToiletList(TOILET_COUNT);			
			Integer bestQualityRank = chooseToilet(toiletList, REJECT_COUNT);
			
			if (bestQualityRank == 1) {
				++successCount;
			}
		}
		System.out.println(successCount + "/" + TEST_COUNT + "=" +  ((double)successCount/TEST_COUNT));
	}
	
	public static Integer chooseToilet(List<Integer> toiletList, Integer REJECT_COUNT) {
		Integer bestQualityRank = Collections.min(toiletList.subList(0, REJECT_COUNT));
		Boolean found = false;
		
		int i = 0;
		for (i=REJECT_COUNT; i<toiletList.size() && !found; ++i) {
			if (toiletList.get(i) < bestQualityRank) {
				bestQualityRank = toiletList.get(i);
				found = true;
			}
		}
		
		if (!found) {
			bestQualityRank = toiletList.get(toiletList.size()-1);
		}
		
		System.out.println("Toilet index: "+ i + " qualityRank: " + bestQualityRank);
		return bestQualityRank;
	}
	
	public static List<Integer> getRandomToiletList(Integer COUNT){
		List<Integer> list = new ArrayList<Integer>(COUNT);
		for (int i=1; i<=COUNT; ++i) {
			list.add(i);
		}
		
		Collections.shuffle(list);
		System.out.println(list);
		
		return list;
	}

}
