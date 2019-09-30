class Extra1 {
	public static void main(String[] args) {
		for(String arg : args) {
			int sample = Integer.parseInt(arg);
			
			sample = sample < 0 ? -sample : sample;
			
			int sum=0;
			while(sample>0) {
				sum += sample%10;
				sample = sample/10;
			}
			
			System.out.println("Summation of digits of " + arg + ": " + sum);
		}
	}
}