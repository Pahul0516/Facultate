using Lab10.Domain;
using Lab10.Repository;
namespace Lab10.Controller;

public class Controller
{
    private RepoElevi repoElevi = new RepoElevi();
    private RepoEchipa repoEchipe = new RepoEchipa();
    private RepoJucator repoJucator = new RepoJucator();
    private RepoMeci repoMeci = new RepoMeci();
    public void load_from_db()
    {
        Database db = new Database(repoElevi, repoEchipe, repoJucator, repoMeci);
    }

    public  IEnumerable<Jucator> raport1(int id_echipa)
    {
        return repoJucator.GetAll().Where(j => j.Echipa.Id==id_echipa).DistinctBy(j => j.Id).OrderBy(j => j.Id).ToList();
    }

    public Tuple<IEnumerable<Jucator>,IEnumerable<Jucator>> raport2(int id_meci)
    {
        var list = repoJucator.GetAll().OfType<JucatorActiv>().Where(j => j.IdMeci == id_meci).ToList();
        var teamIds = list.Select(j => j.IdEchipa).Distinct().ToList();
        var echipa1List = list.Where(j => j.IdEchipa == teamIds[0] && j.Tip!="rezerva").OrderBy(j => j.Id).ToList();
        var echipa2List = list.Where(j => j.IdEchipa == teamIds[1] && j.Tip!="rezerva").OrderBy(j => j.Id).ToList();
        return Tuple.Create((IEnumerable < Jucator >) echipa1List, (IEnumerable < Jucator >) echipa2List);
    }

    public IEnumerable<DTOMeci> raport3(DateTime startDate, DateTime endDate)
    {
        var meciuri = repoMeci.GetAll().Where(m => m.Data >= startDate && m.Data <= endDate).ToList();
        var echipe = repoEchipe.GetAll();
        var rez = from m in meciuri
            join e1 in echipe on m.Echipa1.Id equals e1.Id
            join e2 in echipe on m.Echipa2.Id equals e2.Id
            select new DTOMeci()
            {
                FirstTeamName = e1.Name,
                SecondTeamName = e2.Name
            };
        return rez;
    }

    public Tuple<TeamScoreDTO, TeamScoreDTO> raport4(int id_meci)
    {
        var list = repoJucator.GetAll().OfType<JucatorActiv>().Where(j=> j.IdMeci == id_meci).ToList().Distinct().ToList();
        var teamIds = list.Select(j => j.IdEchipa).Distinct().ToList();
        var Team1 = list.Where(j => j.IdEchipa == teamIds[0]).ToList();
        var scoreTeam1 = Team1.Sum(j => j.NrPuncteInscrise);
        TeamScoreDTO e1 = new TeamScoreDTO(Team1[0].Echipa.Name, scoreTeam1);
        var Team2 = list.Where(j => j.IdEchipa == teamIds[1]).ToList();
        var scoreTeam2 = Team2.Sum(j => j.NrPuncteInscrise);
        TeamScoreDTO e2 = new TeamScoreDTO(Team2[0].Echipa.Name, scoreTeam2);
        return Tuple.Create(e1, e2);
    }
}
