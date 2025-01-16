namespace Lab10;

public class Test{

    private delegate void TestDelegate(); 
    private TestDelegate testDelegate;

    public Test()
    {
        testDelegate = () => System.Console.WriteLine("Test"); 
        testDelegate();
    }
}