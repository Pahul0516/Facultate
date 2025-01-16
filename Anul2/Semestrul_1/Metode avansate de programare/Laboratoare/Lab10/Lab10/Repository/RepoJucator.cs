using Lab10.Domain;

namespace Lab10.Repository;

public class RepoJucator : IRepository<int, Jucator>
{
    List<Jucator> jucatori = new List<Jucator>();
    public Jucator GetById(int id) { return jucatori.FirstOrDefault(j => j.Id == id); }
    public IEnumerable<Jucator> GetAll() { return jucatori; }
    public void Add(Jucator entity) { jucatori.Add(entity); }
    public void Update(Jucator entity)
    {
        var jucatorVechi = GetById(entity.Id);
        if (jucatorVechi != null)
            jucatorVechi.Echipa = entity.Echipa;
    }
    public void Delete(int id) { jucatori.Remove(GetById(id)); }
}