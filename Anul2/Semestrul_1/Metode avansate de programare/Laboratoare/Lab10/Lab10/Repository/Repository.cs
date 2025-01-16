using Lab10.Domain;
namespace Lab10.Repository;


public interface IRepository<ID, E> where E : Entity<ID>
{
    E GetById(ID id); // Retrieve an entity by its identifier
    IEnumerable<E> GetAll(); // Retrieve all entities
    void Add(E entity); // Add a new entity
    void Update(E entity); // Update an existing entity
    void Delete(ID id); // Delete an entity by its identifier
}