class StupidLoop {

    public static int stupidLoop(int N) {
        int mySum = 0;
        int modSum = 0;
        for (int j = N; j > 0; j /= 2) {
            for (int i = 0; i < j; i++) {
                mySum++;
                if (mySum % 4 == 0) {
                    modSum++;
                }
            }
        }
        return mySum;
    }

}
