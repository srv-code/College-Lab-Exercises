using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Summary description for MovieDataReader
/// </summary>
public class MovieCollection {
	public List<string> GetMovies() { 
		List<string> movies = new List<string>();
		movies.Add("movie1");
		movies.Add("movie2");
		movies.Add("movie3");
		return movies;
	}
}