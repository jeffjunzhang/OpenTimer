// This program demonstrates the basica usage of OpenTimer C++ API
// on timing report and path reports.
//
// Design : simple.v
// SDC    : simple.sdc
// Library: osu018_stdcells.lib

#include <ot/timer/timer.hpp>

int main(int argc, char *argv[]) {

  ot::Timer timer;
  
  // Read design
  timer.num_threads(std::thread::hardware_concurrency())
       .celllib("osu018_stdcells.lib", ot::EARLY)
       .celllib("osu018_stdcells.lib", ot::LATE)
       .verilog("simple.v")
       .sdc("simple.sdc");

  // get the top-5 worst critical paths
  auto paths = timer.worst_paths(5);

  for(size_t i=0; i<paths.size(); ++i) {
    std::cout << "----- Critical Path " << i << " -----\n";
    std::cout << paths[i] << '\n';
  }

  // dump the timing graph to dot format for debugging
  std::cout << timer.dump_graph();

  return 0;
}



















