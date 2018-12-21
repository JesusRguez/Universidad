/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package filoapian;

public class filoApiAN {
    public static int tenedores[] = new int[5];
    public static Condition ok[] = new Condition[5];

    public filoApiAN(){
        for (int i=0; i<5; ++i) {
            tenedores[i] = 2;
        }
    }

    public void take_forks(int i){
        while(tenedores[i] != 2){
            ok[i].await();
        }
        tenedores[i+1]--;
        tenedores[i-1]--;
    }

    public void release_forks(itn i){
        tenedores[i+1]++;
        tenedores[i-1]++;
        if (tenedores[i+1] == 2) {
            ok[i+1].signal();
        }
        if (tenedores[i-1] == 2) {
            ok[i-1].signal();
        }
    }
}
