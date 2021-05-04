
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class BitArray implements Clusterable<BitArray>{
	private ArrayList<Boolean> bits;

	public BitArray(String str){
		Stream<String> stream=Stream.of(str);
		bits=stream

	}
	public BitArray(boolean[] bits) {
		//TODO
	}

	@Override
	public double distance(BitArray other) {
		// TODO: Complete
		return 0;
	}

	public static Set<BitArray> readClusterableSet(String path) throws IOException {
		// TODO: Complete. If the file contains bitarrays of different lengths,
		//  retain only those of maximal length
		return null;
	}

	@Override
	public String toString() {
		return bits.toString();
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;
		BitArray bitArray = (BitArray) o;
		return bits.equals(bitArray.bits);
	}

	@Override
	public int hashCode() {
		return Objects.hash(bits);
	}
}
