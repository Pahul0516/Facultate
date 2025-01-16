namespace Lab10.Domain;

public class JucatorActiv : Jucator
{
    public int IdMeci { get; }
    public int IdEchipa { get; }
    public int NrPuncteInscrise { get; set; }
    public string Tip { get; set; }
    
    public JucatorActiv(int idJucator, String nume, string scoala, Echipa echipa, int idMeci, int nrPuncteInscrise, string tip, int idechipa): 
        base(idJucator, nume, scoala, echipa)
    {
        IdMeci = idMeci;
        NrPuncteInscrise = nrPuncteInscrise;
        Tip = tip;
        IdEchipa = idechipa;
    }

    // public override string ToString()
    // {
    //     return
    //         $"{base.ToString()}, {nameof(IdMeci)}: {IdMeci}, {nameof(IdEchipa)}: {IdEchipa}, {nameof(NrPuncteInscrise)}: {NrPuncteInscrise}, {nameof(Tip)}: {Tip}";
    // }
    
    
}