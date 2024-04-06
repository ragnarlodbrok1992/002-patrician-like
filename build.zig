const std = @import("std");
const mach = @import("mach");

// Although this function looks imperative, note that its job is to
// declaratively construct a build graph that will be executed by an external
// runner.
pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});

    const optimize = b.standardOptimizeOption(.{});

    const mach_dep = b.dependency("mach", .{
        .target = target,
        .optimize = optimize,
        .core = true,
    });

    const app = try mach.CoreApp.init(b, mach_dep.builder, .{
        .name = "patrician-like",
        .src = "src/main.zig",
        .target = target,
        .optimize = optimize,
        .deps = &[_]std.Build.Module.Import{},
    });

    if (b.args) |args| app.run.addArgs(args);

    const run_step = b.step("run", "Run the game");
    run_step.dependOn(&app.run.step);
}
