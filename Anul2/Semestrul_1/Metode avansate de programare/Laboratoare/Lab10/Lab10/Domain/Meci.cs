namespace Lab10.Domain;

public class Meci : Entity<int>
{
    public Echipa Echipa1 { get; set; }   
    public Echipa Echipa2 { get; set; }
    public DateTime Data { get; set; }

    public  Meci(int id, Echipa echipa1, Echipa echipa2, DateTime data): base (id)
    {
        Echipa1 = echipa1;
        Echipa2 = echipa2;
        Data = data;
    }
}