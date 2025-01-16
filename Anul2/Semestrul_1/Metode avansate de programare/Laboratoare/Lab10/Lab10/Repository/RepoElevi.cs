using Lab10.Domain;
namespace Lab10.Repository;

public class RepoElevi : IRepository<int, Elev>
{
    List<Elev> Elevi = new List<Elev>();
    public Elev GetById(int id) { return Elevi.FirstOrDefault(elev => elev.Id == id); }
    public IEnumerable<Elev> GetAll() { return Elevi; }
    public void Add(Elev entity) { Elevi.Add(entity); }
    public void Update(Elev entity)
    {
        var elevVechi = GetById(entity.Id);
        if (elevVechi != null)
            elevVechi = entity;
    }
    public void Delete(int id) { Elevi.Remove(GetById(id)); }
}