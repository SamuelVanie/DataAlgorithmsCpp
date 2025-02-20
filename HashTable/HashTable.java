import org.junit.Test;
import static org.junit.Assert.*;
import java.util.List;

public class HashTable {

    private List<HashElement>[] content;
    private final int hashSize;

    public HashTable(int size) {
        this.hashSize = size;
        this.content = new ArrayList<HashElement>[size];
    }

    public int hash(String key) {
        return key.length() % this.hashSize;
    }

    public void insert(String key, int value) {
        int theKey = hash(key);
        List<HashElement> el = this.content[theKey];
        el.insert(new HashElement(key, value));
    }


    public static class HashElement {
        private String key;
        private int value;

        public HashElement(String key, int value) {
            this.key = key;
            this.value = value;
        }

        public String getKey() {
            return key;
        }
        public int getValue() {
            return value;
        }

    }

    public static class HashTableTest {

        @Test
        public void testPutAndGet() {
            
        }

    }
}
