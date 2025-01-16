using Lab10.Domain;

namespace Lab10.Repository;

public class RepoEchipa : IRepository<int, Echipa>
{
    List<Echipa> Echipe = new List<Echipa>();
    public Echipa GetById(int id) { return Echipe.FirstOrDefault(echipa => echipa.Id == id); }
    public IEnumerable<Echipa> GetAll() { return Echipe; }
    public void Add(Echipa entity) { Echipe.Add(entity); }
    public void Update(Echipa entity)
    {
        var echipa_veche = GetById(entity.Id);
        if (echipa_veche == null)
            echipa_veche.Name = entity.Name;
    }
    public void Delete(int id) { Echipe.Remove(GetById(id)); }
    
}