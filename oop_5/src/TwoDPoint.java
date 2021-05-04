
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Objects;
import java.util.Set;
import java.util.stream.Collectors;

public class TwoDPoint implements Clusterable<TwoDPoint>{
	double x;
	double y;
	public TwoDPoint(String str){
		String[] strarr= str.split(",");
		x=Double.parseDouble(strarr[0]);
		y=Double.parseDouble(strarr[1]);
	}
	public TwoDPoint(double x, double y) {
		this.x=x;
		this.y=y;
	}
	@Override
	public double distance(TwoDPoint other) {
		return Math.sqrt((this.x-other.x)*(this.x-other.x)+(this.y-other.y)*(this.y-other.y));
	}

	public static Set<TwoDPoint> readClusterableSet(String path) throws IOException{
		return Files.lines(Paths.get(path)).map(l->new TwoDPoint(l)).collect(Collectors.toSet());
	}

	@Override
	public String toString() {
		return x + "," + y;
	}

	@Override
	public boolean equals(Object other) {
		TwoDPoint otherP = (TwoDPoint) other;
		return (otherP.x == x && otherP.y == y);
	}

	@Override
	public int hashCode() {
		return Objects.hash(x, y);
	}
}
