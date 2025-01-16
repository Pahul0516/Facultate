namespace Lab10.Domain;

public class Jucator : Elev
{
    public Echipa Echipa { get; set; }
    public Jucator(int id, string name, string school, Echipa echipa) : base(id, name, school)
    {
        this.Echipa = echipa;
    }
    
}