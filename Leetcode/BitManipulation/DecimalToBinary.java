
import java.util.Vector;

// Java program to Decimal to binary conversion
// using bitwise operator
// Size of an integer is assumed to be 32 bits

public class DecimalToBinary {
    // Function that convert Decimal to binary
    public Vector<Integer> decToBinary(int n)
    {
        Vector<Integer> binary = new Vector<Integer>();
        // Size of an integer is assumed to be 32 bits
        for (int i = 31; i >= 0; i--) {
            int k = n >> i; // right shift n by i bits
            if ((k & 1) > 0) // check if the last bit is 1
                // System.out.print("0");
                binary.add(0);
            else
                // System.out.print("1");
                binary.add(1);
        }
        return binary;
    }


// driver code
    public static void main(String[] args)
    {
        DecimalToBinary g = new DecimalToBinary();
        int n = 43261596;
        System.out.println("Decimal - " + n);
        System.out.print("Binary - ");
        Vector<Integer> binary = g.decToBinary(n);
        for (int i = 0; i < binary.size(); i++) {
            System.out.print(binary.get(i));
        }
    
    }
}