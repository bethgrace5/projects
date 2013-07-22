package Scheduler;
import java.util.HashMap;
/*list types of Positions, associate which shifts in ListAvailablePeople that can work that position.
 * associate Employee with Position. construct primary and alternate Positions.
 * 
 */
public class Position {
//I thought I'd start by using a hashmap to map a position to names of employees that can work that position.
//note: only front staff taken into consideration. Once I get things running, I'll add janitor/Hot/salad/bakery/etc.	
	HashMap<String, String> positions = new HashMap<String, String>();
	//I don't think I'm using positions.put() correctly yet.
	positions.put("superOpen7","a");
	positions.put("superCashier730","");
	positions.put("cashierOpen83","");
	positions.put("cashierOpen8330","");
	positions.put("cashierMid11","");
	positions.put("cashierMid9","");
	positions.put("coldOpen730","");
	positions.put("superClose12","");
	positions.put("coldClose1","");
	positions.put("cashierClose3","");
	positions.put("cashierClose330","");
}
